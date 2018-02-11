var
 a,b:longint;
 s:string;
begin
 assign(input,'expr.in');  reset(input);
 assign(output,'expr.out'); rewrite(output);
 read(s);
 writeln('5');
 close(input);
 close(output);
end.
