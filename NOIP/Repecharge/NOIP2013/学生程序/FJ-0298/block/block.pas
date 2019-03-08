var ji,h:array[1..100100]of longint;
   { son:array[1..100100,1..2]of longint;}
    ans:int64;{min,}n,j,t:longint;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);{min:=maxlongint;  }
  for j:=1 to n do
    begin
      read(h[j]);
    {  if h[i]<min then begin min:=h[i];f:=i;end; }
    end;


{if n<=1000 then
   begin }
     j:=1; fillchar(ji,sizeof(ji),0);ans:=0;
     repeat

     while ji[j]<h[j] do
       begin
         t:=j+1;
         inc(ji[j]);
         while ji[t]<h[t] do
         begin
           inc(ji[t]);
           inc(t);
         end;
        inc(ans);
       end;
      inc(j);
     until j>n;
     writeln(ans);
 { end
  else
    begin
      fillchar(ji,sizeof(ji),0);
      fillchar(son,sizeof(son),0);
      ans:=0;
      for i:=f downto 1 do
        begin
          son[i,1]:=i-1;
        end;
      for i:=f to n-1 do
        begin
          if son[i,1]<>0 then son[i,1]:=i+1 else son[i,2]:=i+1;
        end;
      cao(f);

      writeln(ans);
    end; }
  close(input);close(output);
end.
