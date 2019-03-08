var
n,p,i,min,j,fs:longint;
a,tz:array[1..1000000]of integer;
max:array[1..2]of longint;
f:boolean;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do tz[i]:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    f:=false;min:=maxlongint;
    for j:=1 to i do
    begin
      if a[j]>0 then begin tz[i]:=tz[i]+a[j];f:=true; end
      else if a[j]<0 then
        if a[j]<min then min:=a[j];
      end;
    if not f then tz[i]:=min;
    end;
  max[1]:=-maxlongint;  max[2]:=1;
  for i:=1 to n do if i=1 then
    begin
      fs:=tz[i];
      max[1]:=fs;
      max[2]:=i
      end else
      begin
        fs:=max[1]+tz[max[2]];
        if fs>max[1] then
          begin
            max[1]:=fs;
            max[2]:=i;
            end;
        end;
      writeln(max[1] mod p);
      close(input);
      close(output);
end.
