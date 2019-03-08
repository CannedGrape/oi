program number;
var
  t,f,a:array[0..1000000] of longint;
  i,n,p,b,k,z,j,l:longint;

function max(a,b:longint):longint;
begin
  if a>b then max:=a else max:=b;
end;

begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p);
  b:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]>=0 then b:=b+1 else b:=b-1;
    end;
  if b=n then
    begin
      t[1]:=a[1];
      for i:=2 to n do t[i]:=t[i-1]+a[i];
      f[1]:=t[1];
      for i:=2 to n do f[i]:=f[i-1]+t[i-1];
      writeln(f[n] mod p);
    end
    else
      if b=-1*n then
        writeln(a[1] mod p)
        else
          begin
            t[1]:=a[1];
            for i:=2 to n do
              begin
                k:=i-1; z:=1;
                while z<>2 do
                if a[k]>0 then
                  begin
                    t[i]:=a[i]+t[k];
                    z:=2;
                  end
                  else
                      k:=k-1;
              end;
            f[1]:=t[1]; z:=1;
            for j:=2 to n do
              begin
              k:=j-1; z:=1;
                while z<>2 do
                if t[k]>0 then
                  begin
                    f[j]:=f[k]+t[k];
                    z:=2;
                  end
                  else
                      k:=k-1;
              end;
            for l:=n downto 1 do
                if f[l]>0 then
                  begin
                    writeln(f[l] mod p);
                    break;
                  end;
      end;
  close(input); close(output);
end.

