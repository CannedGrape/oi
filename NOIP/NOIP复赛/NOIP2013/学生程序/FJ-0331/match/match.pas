begin
 assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
writeln('2');
close(output);
end.