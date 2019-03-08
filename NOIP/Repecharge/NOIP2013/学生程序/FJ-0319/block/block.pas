var h:array[0..100010]of longint;
    n,i,ans,min,m,l:longint;
    j,k:boolean;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  min:=maxlongint;
  for i:=1 to n do
  begin
    read(h[i]);
    if h[i]<min then min:=h[i];
  end;
  for i:=1 to n do h[i]:=h[i]-min;
  ans:=min;h[n+1]:=0;
  repeat
    k:=true;j:=true;m:=1;min:=maxlongint;
    for i:=1 to n+1 do
    begin
      if h[i]<>0 then
        begin
          if j then j:=false;
          if h[i]<min  then min:=h[i];
          k:=false;
        end
      else if j=false then
           begin
             for l:=m to i-1 do
               if h[l]<>0 then dec(h[l],min);
             inc(ans,min);
             m:=i+1;j:=true;min:=maxlongint;
           end
           else m:=i+1;
    end;
  until k;
  writeln(ans);
  close(input);close(output);
end.