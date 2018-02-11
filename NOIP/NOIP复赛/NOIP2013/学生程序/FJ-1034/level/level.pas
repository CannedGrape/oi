var
  n,m,i,j,min,max,l:longint;
  a:array[1..1000,0..1000]of longint;
  f:array[1..1000]of longint;
  b,v:array[1..1000]of boolean;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  read(n,m);fillchar(v,sizeof(v),false);
  for i:=1 to m do
    begin
      read(a[i,0]);
      for j:=1 to a[i,0] do read(a[i,j]);
    end;
  for i:=1 to n do f[i]:=1;
  for i:=1 to m do
    begin
      min:=f[a[i,1]];
      for j:=2 to a[i,0] do if f[a[i,j]]<min then min:=f[a[i,j]];
      fillchar(b,sizeof(b),false);
      for j:=1 to a[i,0] do b[a[i,j]]:=true;
      for j:=a[i,1] to a[i,a[i,0]] do
        begin
          v[j]:=true;
          if (b[j]=false)and(f[j]>=min)then
            begin
              for l:=1 to n do
                if (f[l]>f[j])or(b[l]and(f[l]=f[j]))then
                  f[l]:=f[l]+(f[j]-min+1);
              min:=f[j]+1;
            end;
        end;
      max:=min;
      for j:=1 to n do if f[j]>max then max:=j;
      for j:=1 to n do if v[j]=false then f[j]:=max;
    end;
  max:=f[1];
  for i:=2 to n do if f[i]>max then max:=f[i];
  writeln(max);
  close(input);
  close(output);
end.
