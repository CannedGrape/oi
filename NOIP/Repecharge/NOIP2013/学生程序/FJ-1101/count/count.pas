var a,b:qword;
    f,h,m,i:longint;
    c,k:array[0..8] of longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(a,b);
  c[0]:=1;
  c[1]:=10;
  if b<>0 then begin
  for i:=2 to 8 do
  begin
  c[i]:=c[i-1]*10;
  end;
  for i:=1 to 8 do
  if a<c[i] then begin f:=i;break;end;
  for i:= 2 to f-1 do
  begin
  h:=h+(a div c[i])*c[i-1];
  if (a mod c[i]>(b+1)*c[i-1]) or (a mod c[i]=(b+1)*c[i-1]) then h:=h+c[i-1]
  else if (a mod c[i]>b*c[i-1]) or(a mod c[i]=b*c[i-1]) then h:=h+a mod c[i]-b*c[i-1]+1;
  end;
  h:=h+a div 10;
  if a mod 10<b then k[1]:=0 else h:=h+1;
  if a div c[f-1]>(b+1) then h:=h+c[f-1]
  else if (a div c[f-1]>b) or(a div c[f-1]=b) then h:=h+a mod c[f-1]+1;
  writeln(h);
  end
  else begin
  for i:=2 to 8 do
  begin
  c[i]:=c[i-1]*10;
  end;
  for i:=1 to 8 do
  if a<c[i] then begin f:=i;break;end;
  for i:= 2 to f-1 do
  begin
  h:=h+((a div c[i])-1)*c[i-1];
  if a mod c[i-1]>(b+1)*c[i-2] then h:=h+c[i-1]
  else if (a mod c[i-1]>b*c[i-2]) or(a mod c[i-1]=b*c[i-2]) then h:=h+a mod c[i-1]-b*c[i-2]+1;
  end;
  h:=h+a div 10-1;
  if a mod 10<b then k[1]:=0 else h:=h+1;
  writeln(h);
  end;
  readln;
  readln;
  close(input);
  close(output);
end.
