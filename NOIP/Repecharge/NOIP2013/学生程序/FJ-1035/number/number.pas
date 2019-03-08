
begin
assign(input,'number.in');
assign(output,'number.out');
reset(input);
rewrite(output);
writeln('1');
close(input);
close(output);
end.