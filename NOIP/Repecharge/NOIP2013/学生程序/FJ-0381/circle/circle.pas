var input,output:text;
    n,m,k,x:longint;

procedure putin;
begin
 readln(input,n,m,k,x);
end;

procedure main;
 var i,y:longint;
begin
 m:=m mod n;
 i:=0;
 repeat
 inc(i);
 m:=(m*10) mod n;
 until i=k;
 x:=(x+m) mod n;
end;

procedure putout;
begin
 write(output,x);
end;

begin
 assign(input,'e:\FJ-0381\circle\circle.in');
 assign(output,'e:\FJ-0381\circle\circle.out');
 reset(input);
 rewrite(output);
 putin;
 main;
 putout;
 close(input);
 close(output);
end.
