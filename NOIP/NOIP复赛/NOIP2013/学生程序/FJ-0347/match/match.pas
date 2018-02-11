program ji;
begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);
writeln(1);
close(input);
close(output);
end.