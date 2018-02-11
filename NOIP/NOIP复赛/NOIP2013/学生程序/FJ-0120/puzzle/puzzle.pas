var
  n,m,q,i,j,k,t,x,go,start:longint;
  Ex,Ey,Sx,Sy,Tx,Ty:longint;
  map:array[0..30,0..30] of longint;
  first,next,endl,w:array[0..90000] of longint;
  dis:array[0..90000] of longint;


begin
assign(input,'puzzle.in'); reset(input);
assign(output,'puzzle.out'); rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
   begin
    for j:=1 to m do
     begin
       read(x);
       if x=0 then map[i,j]:=0
       else map[i,j]:=1;
     end;
    readln;
   end;


  for k:=1 to q do
   begin
     readln(Ex,Ey,Sx,Sy,Tx,Ty);
     t:=map[Ex,Ey];
     map[Ex,Ey]:=3;

     if (map[Tx,TY]=0) then begin writeln(-1); continue; end;

     if (map[Tx,Ty]=1) then
      begin
        if (map[Tx+1,Ty]<>3) and (map[Tx,Ty+1]<>3) and (map[Tx-1,Ty]<>2)
          and (map[Tx,Ty-1]<>3) then
        writeln(-1)  else  writeln(abs(Tx-Sx)+(Ty-Sy));
      end;
     if (map[Tx,Ty]=3) then writeln(abs(Tx-Sx)+(Ty-Sy));
     map[Ex,Ey]:=t;
   end;
close(input); close(output);
end.
