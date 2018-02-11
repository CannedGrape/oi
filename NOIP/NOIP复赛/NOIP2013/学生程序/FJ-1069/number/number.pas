program number;    {beiyong}
var
  n,i,p,n1:longint;
  a,te,fen:array[1..1000000]of longint;
  b:boolean;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  b:=true;
  for i:=1 to n do
    begin
      read(a[i]);
      if (a[i]>=0)then begin
                       b:=false;
                       break;
                     end;
    end;
  if b then writeln(a[1] mod p) else
  close(input);
  close(output);
end.
