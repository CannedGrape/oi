program circle;
 var n,m,k,x,ans:int64;
function go(xx:longint):longint;
 var t:longint;
 begin
  if xx=1 then exit(10 mod n)
  else
    begin
     t:=xx mod 2;
     go:=(sqr(go(xx div 2) mod n) mod n);
      if t=1 then go:=go*(10 mod n) mod n;
    end;
 end;
 begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
   readln(n,m,k,x);
    //10^k  * m  mod n;
    ans:=(go(k) mod n)*(m mod n) mod n;
    ans:=(ans+x) mod n;
     write(ans);
  close(input);close(output);
 end.