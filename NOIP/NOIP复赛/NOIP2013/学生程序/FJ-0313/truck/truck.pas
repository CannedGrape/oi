program truck;
 var n,m,i,j,x,y,z,k,t,q:longint;
     w:array[0..10,0..10] of longint;
     fa:array[0..10001] of longint;
begin
 assign(input,'truck.in'); reset(input);
 assign(output,'truck.out'); rewrite(output);
 readln(n,m);
 fillchar(w,sizeof(w),$7f);
 for i:=1 to m do
  begin
   readln(x,y,z);
   if (z>w[x,y]) or (w[x,y]>100000) then
    begin
     w[x,y]:=z;
     w[y,x]:=z;
    end;
  end;
 for k:=1 to n do
  for i:=1 to n do
   if (i<>k) and (w[i,k]<=100000) then
    for j:=1 to n do
     if (j<>i) and (j<>k) and (w[j,k]<=100000) then
      if w[i,j]>100000 then
       begin
        if w[i,k]<w[k,j] then
         begin
          w[i,j]:=w[i,k];
          w[j,i]:=w[i,k];
         end
         else
          begin
           w[i,j]:=w[k,j];
           w[j,i]:=w[k,j];
          end;
       end
      else
      if (w[i,j]<=w[i,k]) and (w[i,j]<=w[k,j]) then
       if w[i,k]<w[k,j] then
        begin
         w[i,j]:=w[i,k];
         w[j,i]:=w[i,k];
        end
        else
         begin
          w[i,j]:=w[k,j];
          w[j,i]:=w[k,j];
         end;
 readln(q);
 for i:=1 to q do
  begin
   readln(x,y);
   if w[x,y]<=100000 then writeln(w[x,y])
    else writeln('-1');
  end;
 close(input); close(output);
end.


