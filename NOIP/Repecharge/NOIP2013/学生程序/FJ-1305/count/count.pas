program count;
var
  ans,i,j,n,x:longint;
  s,sx:string;
  a:array[1..1000000] of longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);
  {if x<>0 then
    begin
      ans:=0;
      a[1]:=1;
      a[10]:=a[1]*10+10;
      a[100]:=a[10]*10+100;
      a[1000]:=a[100]*10+1000;
      a[10000]:=a[1000]*10+10000;
      a[100000]:=a[10000]*10+100000;
      a[1000000]:=a[100000]*10+1000000;
      j:=1000000;
      while true do
        begin
          ans:=ans+(n div j  mod 10) *a[j div 10];
          if n div j mod 10>x then
            ans:=ans+j
          else
            if n div j mod 10=x then
              ans:=ans+1+n div (j div 10 mod 10);
          j:=j div 10;
        end;
      writeln(ans);
    end
  else
    begin}
      str(x,sx);ans:=0;
      for i:=1 to n do
        begin
          str(i,s);
          for j:=1 to length(s) do
            if copy(s,j,1)=sx then
              ans:=ans+1;
        end;
      writeln(ans);
    {end;}
  close(input);close(output);
end.
