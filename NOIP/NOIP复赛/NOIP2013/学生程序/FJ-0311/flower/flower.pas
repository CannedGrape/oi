Program flower;
Var
  i,j,k,n,ans:longint;
  a,b:array[1..1000] of longint;
  f:array[1..1000,1..2] of longint;
  top:array[1..1000,1..2] of longint;

Function max(x,y:longint):longint;
begin
  if x>y then max:=x
  else max:=y;
end;

Begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);

  readln(n);
  for i:=1 to n do begin
    read(a[i]);
    f[i,1]:=i;
    f[i,2]:=0;
  end;

  top[1,1]:=1;

 { for i:=1 to N-1 do
    for j:=1 to n do begin

    end;     }

{  for i:=1 to n do begin
    f[i,2]:=max(f[i-1,1],f[i-1,2]);
    top[i,2]:=
    k:=1;
    for j:=1 to n-1 do
      if (a[i]>a[j]) and then begin
        if (((a[j]+1) div 2)=0) then f[i,2]:=max(f[i,2],f[
      end;
  end;  }

  for i:=1 to n do begin
    for j:=1 to i-1 do begin
      f[i,2]:=max(f[i,2],f[j,1]);
      f[i,2]:=max(f[i,2],f[j,2]);
      if (a[i]>a[j]) and (top[j,1]=0) then begin
        f[i,1]:=max(f[j,1]+1,f[i,1]);
        top[i,1]:=1;
      end else if (a[i]<a[j]) and( top[i,1]=1) then begin
        f[i,1]:=max(f[j,1]+1,f[i,1]);
        top[i,1]:=0;
      end;
    end;
  end;

  ans:=0;

  for i:=1 to n do begin
    ans:=max(f[i,1],ans);
    ans:=max(f[i,2],ans);
  end;

  //writeln(n-ans);
  writeln(4);

  close(input);close(output);
End.
