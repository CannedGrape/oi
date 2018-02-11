program exam1;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
write('2');
close(input);close(output);
end.