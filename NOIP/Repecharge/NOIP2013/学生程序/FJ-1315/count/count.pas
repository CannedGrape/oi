program count;
var
  n,x,tatal,j,i,l,z,k,kk:longint;
  a:array[0..100] of longint;
begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(n,x);
  tatal:=1; j:=1; z:=0; k:=1;
  if n>=10 then
  begin
    for i:=10 to n do
      begin
        z:=1; k:=1; j:=1;
        while k<>0 do
          begin
            kk:=i div 10;
            if kk<10 then k:=0;
            z:=z+1;
          end;
      l:=i;
      while j<=z do
        begin
          a[j]:=l mod 10;
          l:=l div 10;
          j:=j+1;
        end;
      for j:=1 to z do
        begin
          if a[j]=x then tatal:=tatal+1;
        end;
    end;
  end;
  writeln(tatal);
  close(input); close(output);
end.
