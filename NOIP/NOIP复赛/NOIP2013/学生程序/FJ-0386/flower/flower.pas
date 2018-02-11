program flower;
var   n,i,j,t,k,s1,s2,x:longint; p:boolean;
   a,b1,b2:array[1..1000000]of longint;
begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  read(n);
  for i:=1 to n do
   begin
    b1[i]:=1;
    b2[i]:=1;
    read(a[i]);
   end;

    i:=1;
    p:=false;
    j:=1;
    repeat
     t:=a[i];
     repeat
      inc(j);
      if a[j]<t then t:=a[j];
      until (a[j]>t)or(j=n);

    if j<>n then
     begin
      if a[j]>t then
       if j-i>1 then
        for x:=i+1 to j-2 do b1[x]:=0;
     end
     else
      begin
      p:=true;
      if a[j]>t then
       if j-i>1 then
        for x:=i+1 to j-2 do b1[x]:=0;
      end;

     j:=j-1; i:=j;  t:=a[i];
     repeat
      inc(j);
      if a[j]>t then t:=a[j];
     until (a[j]<t)or(j=n);

    if j<>n then
     begin
      if a[j]>t then
       if j-i>1 then
        for x:=i+1 to j-2 do b1[x]:=0;
     end
     else
      begin
      p:=true;
      if a[j]>t then
       if j-i>1 then
        for x:=i+1 to j-2 do b1[x]:=0;
      end;
      i:=j-1;


     if j=n then p:=true;
     until p;

     for i:=1 to n do
      if b1[i]=0 then s1:=s1+1;




      i:=1;
    p:=false;
    j:=1;
    repeat
     t:=a[i];
     repeat
      inc(j);
      if a[j]<t then t:=a[j];
      until (a[j]>t)or(j=n);

    if j<>n then
     begin
      if a[j]>t then
       if j-i>1 then
        for x:=i+1 to j-2 do b2[x]:=0;
     end
     else
      begin
      p:=true;
      if a[j]>t then
       if j-i>1 then
        for x:=i+1 to j-2 do b2[x]:=0;
      end;

     j:=j-1; i:=j;  t:=a[i];
     repeat
      inc(j);
      if a[j]>t then t:=a[j];
     until (a[j]<t)or(j=n);

    if j<>n then
     begin
      if a[j]<t then
       if j-i>1 then
        for x:=i+1 to j-2 do b2[x]:=0;
     end
     else
      begin
      p:=true;
      if a[j]<t then
       if j-i>1 then
        for x:=i+1 to j-2 do b2[x]:=0;
      end;
      i:=j-1;


     if j=n then p:=true;
     until p;

     for i:=1 to n do
      if b2[i]=0 then s2:=s2+1;

    if s2>s1 then write(n-s1)
      else write(n-s2);
      close(input); close(output);
end.
