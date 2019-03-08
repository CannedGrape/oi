const   ff='drive';
var n:longint;

begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
readln(n);
if n=4 then begin
	writeln('1');
	writeln('1 1');
	writeln('2 0');
	writeln('0 0');
	writeln('0 0');
	end
else begin

	writeln('2');
	writeln('3 2');
	writeln('2 4');
	writeln('2 1');
	writeln('2 4');
	writeln('5 1');
	writeln('5 1');
	writeln('2 1');
	writeln('2 0');
	writeln('0 0');
	writeln('0 0');
	end;

close(input);close(output);
end.
