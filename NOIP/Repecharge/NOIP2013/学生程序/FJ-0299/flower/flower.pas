var
  n,m,i,j:longint;
  xx:boolean;
  //c:array[1..100000] of boolean;
  h,g:array[1..100000] of longint;
procedure try;
begin
  for i:=2 to n do
    begin
      if ((xx=true)and(h[i]<g[j]))
           or((xx=false)and(h[i]>g[j]))  then
        begin
          g[j]:=h[i]; //dec(m);
        end
        else
          if h[i]<>g[j] then //dec(m)
            begin
              inc(j); g[j]:=h[i];
              if xx=true then xx:=false
                else xx:=true;
            end;
    end;
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  //m:=n;
  for i:=1 to n do
    read(h[i]);
  //2i-1<2i
  xx:=true;
  g[1]:=h[1];  j:=1;
  try;
  m:=j;
  {for i:=2 to n do
    begin
      if ((xx=true)and(h[i]<g[j]))
           or((xx=false)and(h[i]>g[j]))  then
        begin
          g[j]:=h[i]; dec(m);
        end
        else
          if h[i]=g[j] then dec(m)
            else
            begin
              inc(j); g[j]:=h[i];
              if xx=true then xx:=false
                else xx:=true;
            end;
    end;  }
  //2i-1>2i
  if m<n then
    begin
     xx:=false; g[1]:=h[1]; j:=1;
     try;
     if j>m then m:=j;
    end;
  write(m);
  close(input);close(output);
end.