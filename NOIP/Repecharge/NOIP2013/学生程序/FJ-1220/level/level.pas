program ex;
  var a,c:array[0..1000]of longint;
      b:array[0..1000]of boolean;
      i,j,k,n,l,t,m,max:longint;
      f:boolean;
  function le(p:longint):boolean;
    var i,j:longint;
    begin
     le:=false;
     for i:=1 to p do
      if b[c[i]] then
       exit(true);
    end;
  begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
   readln(n,m);
   fillchar(b,sizeof(b),true);
   k:=1;
   for i:=1 to m do
    begin
     read(t);
     f:=false;
     for j:=1 to t do
      read(c[j]);
     if le(t) then
      for j:=1 to t do
       begin
        for k:=j+1 to t do
         if a[c[k]]>=a[c[j]] then
           a[c[j]]:=a[c[k]]+1;
         if max<a[c[j]] then
          max:=a[c[j]];
         b[c[j]]:=false;
        end;
    end;
   write(max+1);
  close(input);
  close(output);
  end.
