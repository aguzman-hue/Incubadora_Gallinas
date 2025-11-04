`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 20.10.2025 19:21:31
// Design Name: 
// Module Name: permiso_unit
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


// permiso_unit.v
// Genera un vector de permiso jerárquico: cada nivel puede acceder a su piso y los inferiores

module permiso_unit(
    input  wire [3:0] nivel,     // Piso actual en formato one-hot (solo un bit activo)
    input  wire [3:0] piso_req,  // Pisos solicitados (también one-hot)
    output wire [3:0] permiso    // Vector de permiso resultante
);

    reg [3:0] mask; // Máscara de acceso según el nivel

    // Lógica combinacional para definir la máscara de acceso
    always @(*) begin
        case (nivel)
            4'b0001: mask = 4'b0001; // Piso 1 → solo puede ir al piso 1
            4'b0010: mask = 4'b0011; // Piso 2 → puede ir a piso 1 y 2
            4'b0100: mask = 4'b0111; // Piso 3 → puede ir a piso 1, 2 y 3
            4'b1000: mask = 4'b1111; // Piso 4 → puede ir a cualquier piso
            default: mask = 4'b0000; // Valor por defecto (ningún permiso)
        endcase
    end

    // El permiso final es la intersección entre la máscara y los pisos solicitados
    assign permiso = mask & piso_req;
endmodule
