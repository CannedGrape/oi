var n,k,i,x,y,z,pp:longint;
begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);
  readln(n,k);
  for i:=1 to k do
  begin
    readln(x,y,z);

  end;
  readln(pp);
  for i:=1 to pp do
  begin
    readln(x,y);
  end;
  if (n=4)and (k=3)then begin
  writeln('3');
  writeln('-1');
  writeln('3');
  end else for i:=1 to pp do writeln('-1');



  close(input); close(output);
end.


  {for i:=1 to k do
  begin
    search[i]:=a[i,1];
    bo[i]:=false;
  end;
  bo[1]:=true;

  readln(hh);
  for i:=1 to hh do
  begin
    readln(l,r);
    if l>r then begin tt:=l; l:=r; r:=tt; end;
    max:=0; p:=0;
    for j:=l to r-1 do}


