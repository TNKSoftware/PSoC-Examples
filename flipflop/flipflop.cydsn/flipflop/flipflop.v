`include "cypress.v"

module flipflop (
	input   button_in,
	output  led_out
);

reg ff;

always @(posedge button_in)
begin
    ff = ~ff;
end

assign led_out = ff;

endmodule
