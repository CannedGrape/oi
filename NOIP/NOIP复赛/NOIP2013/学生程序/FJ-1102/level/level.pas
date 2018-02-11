var f:array[1..1000,1..1000] of longint;
    s:array[1..1000] of longint;
    i,j,k,ans,n,m,max,mm:longint;
    bo:boolean;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  max:=0; ans:=2;
  for i:=1 to m do
    begin
      read(s[i]);
      if s[i]>max then max:=s[i];
      for j:=1 to s[i] do
        read(f[i,j]);
    end;
  for i:=1 to max do
   begin
    bo:=false;
    mm:=f[1,i];
    for j:=1 to m do
    begin
     for k :=1 to s[j] do
      begin
       if (f[j,k]<>mm) and (f[j,1]<f[1,i]) then bo:=true
       else bo:=false;
      end;
     if bo then break;
    end;
     if bo then ans:=ans+1;
    end;
   writeln(ans);
   close(input);
   close(output);
end.