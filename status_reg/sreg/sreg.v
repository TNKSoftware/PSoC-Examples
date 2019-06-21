`include "cypress.v"

module sreg (
	output [7:0] result,
	input clock
);

reg[7:0] res_reg;
reg isr_reg;

always @(posedge clock)
begin
    res_reg = res_reg + 1'b1;
end

assign result = res_reg;

endmodule