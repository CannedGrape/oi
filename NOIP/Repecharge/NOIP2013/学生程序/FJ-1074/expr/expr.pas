 program expr;
 const max=100001;
 var c : array[ 1..max ] of char;
     a : array[ 1..max ] of longint;
     i : longint;
     sum : longint;
     s : string;
 begin
 assign(input,'expr.in');
 reset(input);
 assign(output,'expr.out');
 rewrite(output);
 for i := 1 to max do read(a[i],c[i]);
 for i := 1 to max do
  begin
   if (c[i]='+') then sum := a[i] + a[i + 1];
   if (c[i]='*') then sum := a[i] * a[i + 1];
  end;
 str(sum,s);
 if (length(s) > 4) then s:=copy(s,1,4);
 writeln(s);
 close(input);
 close(output);
 end.

