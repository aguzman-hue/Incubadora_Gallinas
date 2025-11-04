`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 20.10.2025 19:21:31
// Design Name: 
// Module Name: elevator_moore
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


// elevator_moore.v
// FSM tipo Moore: cambia de estado si hay permiso y solicitud válida

module elevator_moore(
    input  wire       clk,         // Señal de reloj
    input  wire       rst_n,       // Reset activo en bajo
    input  wire [3:0] permiso,     // Vector de pisos permitidos
    input  wire [3:0] piso_req,    // Pisos solicitados
    output reg  [1:0] state,       // Estado actual codificado (2 bits)
    output reg  [3:0] piso_out     // Piso actual en formato one-hot
);

    // Codificación de estados (cada uno representa un piso)
    localparam S0 = 2'b00; // Piso 1
    localparam S1 = 2'b01; // Piso 2
    localparam S2 = 2'b10; // Piso 3
    localparam S3 = 2'b11; // Piso 4

    reg [1:0] next_state; // Estado siguiente

    // Lógica de transición: si hay solicitud y permiso, cambia de estado
    always @(*) begin
        next_state = state; // Por defecto, se queda en el mismo estado

        if (piso_req[0] && permiso[0]) next_state = S0;
        else if (piso_req[1] && permiso[1]) next_state = S1;
        else if (piso_req[2] && permiso[2]) next_state = S2;
        else if (piso_req[3] && permiso[3]) next_state = S3;
    end

    // Actualización del estado en flanco positivo del reloj o reset
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= S0; // Al reset, inicia en piso 1
        else
            state <= next_state;
    end

    // Salida tipo Moore: depende solo del estado actual
    always @(*) begin
        case (state)
            S0: piso_out = 4'b0001;
            S1: piso_out = 4'b0010;
            S2: piso_out = 4'b0100;
            S3: piso_out = 4'b1000;
            default: piso_out = 4'b0001; // Valor por defecto
        endcase
    end
endmodule
