const xx=99999997;
var a,b,suma,sumb:array[0..1000000] of longint;
    i,n,tot:longint;
begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
   begin
    read(a[i]);
    suma[i]:=a[i]-a[i-1];
   end;
  readln;
  for i:=1 to n do
   begin
    read(b[i]);
    sumb[i]:=b[i]-b[i-1];
   end;
  for i:=1 to n do
   if ((sumb[i]<0) and (suma[i]>0)) or ((sumb[i]>0) and (suma[i]<0)) then
    begin
     tot:=(tot+1) mod xx;
     suma[i+1]:=a[i+1]-a[i];
    end;
  writeln(tot);
  close(input); close(output);
end.
