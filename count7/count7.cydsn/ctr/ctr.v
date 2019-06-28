`include "cypress.v"

module ctr (
	output  result,
	input   clock,
    input   count_reset
);

wire data_tc;
reg [6:0] count; 
reg result_reg;
 
cy_psoc3_count7 #(.cy_period(7'b111),.cy_route_ld(1),.cy_route_en(1))
DataCounter(
    .clock(clock),
    .reset(1'b0),
    .load(count_reset),
    .enable(1'b1),
    .count(count),
    .tc(data_tc)
);
    
always @(posedge clock)
begin
    if(data_tc)
    begin
        result_reg = ~result_reg;
    end
end

assign result = result_reg;

endmodule
