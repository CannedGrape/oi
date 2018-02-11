//RP++
var n,m,k,x,i,j:longint;o:qword;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);

  readln(n,m,k,x);

  if (n=1) then begin
    writeln(x);
    exit;
  end;

  if n<=10 then begin
    for i:=1 to 10 do begin
      if x>=n-m then x:=x-(n-m)
      else x:=x+m;
    end;
    writeln(x);
    exit;
  end;

  if x mod 10=0 then begin
    for i:=1 to 10 do begin
     if x>=n-m then x:=x-(n-m)
      else x:=x+m;
    end;

    for i:=2 to k do begin
      x:=x+10*m;
      if x>=n then x:=x mod n;
    end;
    writeln(x);
    exit;
  end;

  o:=1;
  for i:=1 to k do o:=o*10;
  for i:=1 to o do begin
     if x>=n-m then x:=x-(n-m)
      else x:=x+m;
    end;
  writeln(x);

  close(input);
  close(output);
end.
