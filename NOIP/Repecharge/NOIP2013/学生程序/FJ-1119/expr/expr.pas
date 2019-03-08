program expr;
var i,a1,code,a2,a3,a4,c,d:integer;
    l:longint;
    ans:longint;
    s,r:char;

begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(a1,s,a2,r,a3);
  ans:=a1+a2*a3;
  writeln(ans);



  close(input);
  close(output);
end.

