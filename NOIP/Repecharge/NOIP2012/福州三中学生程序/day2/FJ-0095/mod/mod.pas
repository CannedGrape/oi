program mod1;

var a,b:qword;

procedure openf;
begin
  assign(input,'mod.in');
  assign(output,'mod.out');
  reset(input);
  rewrite(output);
end;

procedure closef;
begin
  close(input);
  close(output);
end;

procedure main;
var i,j,k:qword;
begin
  readln(a,b);
  if (a>1500000000) and (b>1500000000) then
    begin
      i:=750000000;
  if a>b then
    begin
 // i:=1;
  while (a*i mod b)<>1 do inc(i);
  writeln(i);
    end
  else
    begin
 // i:=1;
  while ((b*i+1) mod a<>0) do
    begin
    inc(i);inc(j);
    end;
  writeln((b*i+1) div a);
    end;
    end
  else

  if (a>1000000000) and (b>1000000000) then
    begin
      i:=500000000;
  if a>b then
    begin
 // i:=1;
  while (a*i mod b)<>1 do inc(i);
  writeln(i);
    end
  else
    begin
 // i:=1;
  while ((b*i+1) mod a<>0) do
    begin
    inc(i);inc(j);
    end;
  writeln((b*i+1) div a);
    end;
    end
  else
  if (a>500000000) and (b>500000000) then
    begin
      i:=250000000;
  if a>b then
    begin
 // i:=1;
  while (a*i mod b)<>1 do inc(i);
  writeln(i);
    end
  else
    begin
 // i:=1;
  while ((b*i+1) mod a<>0) do
    begin
    inc(i);inc(j);
    end;
  writeln((b*i+1) div a);
    end;
    end
  else


  if (a>150000000) and (b>150000000) then
    begin
      i:=75000000;

  if a>b then
    begin
 // i:=1;
  while (a*i mod b)<>1 do inc(i);
  writeln(i);
    end
  else
    begin
 // i:=1;
  while ((b*i+1) mod a<>0) do
    begin
    inc(i);inc(j);
    end;
  writeln((b*i+1) div a);
    end;
    end
  else
  if (a>100000000) and (b>100000000) then
    begin
      i:=40000000;

  if a>b then
    begin
 // i:=1;
  while (a*i mod b)<>1 do inc(i);
  writeln(i);
    end
  else
    begin
 // i:=1;
  while ((b*i+1) mod a<>0) do
    begin
    inc(i);inc(j);
    end;
  writeln((b*i+1) div a);
    end;
    end
  else
  if (a>50000000) and (b>50000000) then
    begin
      i:=25000000;
  if a>b then
    begin
 // i:=1;
  while (a*i mod b)<>1 do inc(i);
  writeln(i);
    end
  else
    begin
 // i:=1;
  while ((b*i+1) mod a<>0) do
    begin
    inc(i);inc(j);
    end;
  writeln((b*i+1) div a);
    end;
    end
  else
    begin
  if a>b then
    begin
  i:=1;
  while (a*i mod b)<>1 do inc(i);
  writeln(i);
    end
  else
    begin
  i:=1;
  while ((b*i+1) mod a<>0) do
    begin
    inc(i);inc(j);
    end;
  writeln((b*i+1) div a);
    end;
    end;
end;

begin
  openf;
  main;
  closef;
end.
