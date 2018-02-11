program number;
var
  n,p,i:longint;
  s,a,fs:array[1..1000000] of longint;
  f:array[1..1000000] of boolean;
function qm(x:longint):longint;
var
  i,num:longint;
begin
  num:=0;
  for i:=1 to x do
    begin
      if f[i] = false then
        begin
          num:=num+a[i];
        end;
    end;
  exit(num);
end;

begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);


  s[1]:=a[1];f[1]:=true;
  for i:=2 to n do
    begin
      if f[i-1] then
        begin
          if s[i-1]<s[i-1]+a[i] then
            begin
              s[i]:=s[i-1]+a[i];
              //writeln(i,'  vcbf  ',s[i]);
              f[i]:=true;
            end
          else if s[i-1]=s[i-1]+a[i] then
              begin
                s[i]:=s[i-1];
                f[i]:=true;
              end
          else
            begin
              s[i]:=s[i-1];
              f[i]:=false;
            end;
          if s[i] = a[i] then f[i]:=true
          else if s[i]<a[i] then
              begin
                s[i]:=a[i];
                f[i]:=true;
              end;
        end
      else
        begin

          if s[i-1]<s[i-1]+a[i]+qm(i-1) then
            begin
              s[i]:=s[i-1]+a[i]+qm(i-1);
              f[i]:=true;
            end
          else if s[i-1]=s[i-1]+a[i]+qm(i-1) then
              begin
                s[i]:=s[i-1]+a[i]+qm(i-1);
                f[i]:=true;
              end
          else
            begin
              s[i]:=s[i-1];
              f[i]:=false;
            end;
          if s[i]=a[i] then f[i]:=true
          else if s[i]<a[i] then
            begin
              s[i]:=a[i];
              f[i]:=true;
            end;
        end;
    end;

  //for i:=1 to n do writeln(s[i]);
  //writeln;
  //for i:=1 to n do writeln(f[i]);

  fs[1]:=s[1];
  for i:=2 to n do
    begin
      if fs[i-1]+s[i-1]>fs[1] then fs[i]:=fs[i-1]+s[i-1]
      else fs[i]:=fs[1];
    end;
  //for i:=1 to n do writeln(fs[i]);
  //writeln;
  if fs[n]< 0 then writeln('-',abs(fs[n]) mod p)
  else
  writeln(fs[n] mod p);
  //readln;readln;readln;
  close(input);close(output);
end.
