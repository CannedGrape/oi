var first,n,m,k,x,ans:int64;
    yushu:array[0..1000000]of int64;
begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input); rewrite(output);
  readln(n,m,k,x);
  first:=1;
  yushu[1]:=10 mod n;
  repeat
    inc(first);
    yushu[first]:=(yushu[first-1]*10) mod n;
  until yushu[first]=yushu[first-1];
  if k mod first=0 then ans:=(x+(m mod n) * yushu[first] ) mod n
  else ans:=(x+(m mod n) * yushu[k mod first] ) mod n ;
  writeln(ans);
  close(input); close(output);
end.

