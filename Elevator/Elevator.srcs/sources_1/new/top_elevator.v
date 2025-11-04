`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 20.10.2025 19:21:31
// Design Name: 
// Module Name: top_elevator
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

// top_elevator.v
// Conecta el generador de permisos y la FSM Moore

module top_elevator(
    input  wire        clk,           // Reloj
    input  wire        rst_n,         // Reset activo en bajo
    input  wire [3:0]  nivel,         // Piso actual (one-hot)
    input  wire [3:0]  piso_req,      // Pisos solicitados (one-hot)
    output wire [3:0]  permiso_out,   // Vector de permisos generados
    output wire [1:0]  estado,        // Estado actual codificado
    output wire [3:0]  piso_actual    // Piso actual en formato one-hot
);

    // Instancia del generador de permisos
    permiso_unit pu (
        .nivel(nivel),
        .piso_req(piso_req),
        .permiso(permiso_out)
    );

    // Instancia de la FSM Moore
    elevator_moore moore_fsm (
        .clk(clk),
        .rst_n(rst_n),
        .permiso(permiso_out),
        .piso_req(piso_req),
        .state(estado),
        .piso_out(piso_actual)
    );
endmodule
