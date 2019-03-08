program number;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
 write(21);
close(input);close(output);
end.