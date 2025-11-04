`timescale 1ns / 1ps

module tb_permiso3_paseo;
    reg clk;
    reg rst_n;
    reg [3:0] nivel;          // Piso actual (nivel 3)
    reg [3:0] piso_req;       // Piso solicitado
    wire [3:0] permiso_out;   // Permisos generados
    wire [1:0] estado;        // Estado FSM
    wire [3:0] piso_actual;   // Piso actual (one-hot)

    // Instancia del sistema
    top_elevator uut (
        .clk(clk),
        .rst_n(rst_n),
        .nivel(nivel),
        .piso_req(piso_req),
        .permiso_out(permiso_out),
        .estado(estado),
        .piso_actual(piso_actual)
    );

    // Generador de reloj: 10 ns de periodo
    initial clk = 0;
    always #5 clk = ~clk;

    // Estímulos de prueba
    initial begin
        // 🚦 Inicialización
        rst_n = 0;
        nivel = 4'b0100;       // Nivel 3 activo
        piso_req = 4'b0000;    // Sin solicitud aún
        #20;

        // 🔄 Activar sistema
        rst_n = 1;
        #10;

        // 🟢 Solicitar piso 1 → permitido desde nivel 3
        piso_req = 4'b0001;
        #20;

        // 🟢 Solicitar piso 2 → permitido
        piso_req = 4'b0010;
        #20;

        // 🟢 Solicitar piso 3 → permitido
        piso_req = 4'b0100;
        #20;

        // 🔴 Solicitar piso 4 → NO permitido desde nivel 3
        piso_req = 4'b1000;
        #20;

        // 🛑 Finalizar simulación
        $stop;
    end
endmodule
