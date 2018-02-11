var i,j,k,t,m,n,q,a1,a2,b1,b2,c1,c2,ans,l1,l2,l,h:longint;
    d,f,d1:array[0..35,0..35] of longint;
    c:array[0..1005,1..3] of longint;
procedure find1(x,y,z:longint);
   begin
    if (x=a1) and (y=a2) then
     begin
     if ans>z then ans:=z
     end
     else
     begin
      if f[x+1,y]=1 then begin f[x+1,y]:=2; find1(x+1,y,z+1); f[x+1,y]:=1; end;
      if f[x-1,y]=1 then begin f[x-1,y]:=2; find1(x-1,y,z+1); f[x-1,y]:=1; end;
      if f[x,y+1]=1 then begin f[x,y+1]:=2; find1(x,y+1,z+1); f[x,y+1]:=1; end;
      if f[x,y-1]=1 then begin f[x,y-1]:=2; find1(x,y-1,z+1); f[x,y-1]:=1; end;
     end;
   end;
procedure find2(x,y,z,o:longint);
   begin
    if (x+1=b1) and (y=b2) or (x-1=b1) and (y=b2) or (x=b1) and (y+1=b2) or (x=b1) and (y-1=b2) then
    begin
    if (l1=0) and (l2=1) then
     begin
      d1:=f;
      c[1,1]:=a1; c[1,2]:=a2; c[1,3]:=0;
      f[a1,a2]:=3; h:=0;t:=1;  l:=0;
      while h<t do
       begin
        inc(h);
        if f[c[h,1]+1,c[h,2]]=1 then
         begin f[c[h,1]+1,c[h,2]]:=3; inc(t); c[t,1]:=c[h,1]+1; c[t,2]:=c[h,2]; c[t,3]:=c[h,3]+1; end;
        if f[c[h,1]-1,c[h,2]]=1 then
         begin f[c[h,1]-1,c[h,2]]:=3; inc(t); c[t,1]:=c[h,1]-1; c[t,2]:=c[h,2]; c[t,3]:=c[h,3]+1; end;
        if f[c[h,1],c[h,2]+1]=1 then
         begin f[c[h,1],c[h,2]+1]:=3; inc(t); c[t,1]:=c[h,1]; c[t,2]:=c[h,2]+1; c[t,3]:=c[h,3]+1; end;
        if f[c[h,1],c[h,2]-1]=1 then
         begin f[c[h,1],c[h,2]-1]:=3; inc(t); c[t,1]:=c[h,1]; c[t,2]:=c[h,2]-1; c[t,3]:=c[h,3]+1; end;
        if f[c[h,1]+1,c[h,2]]=2 then begin l:=c[h,3]+1;  break; end;
        if f[c[h,1]-1,c[h,2]]=2 then begin l:=c[h,3]+1;  break; end;
        if f[c[h,1],c[h,2]+1]=2 then begin l:=c[h,3]+1;  break; end;
        if f[c[h,1],c[h,2]-1]=2 then begin l:=c[h,3]+1;  break; end;
       end;
      if l<>0 then
      begin
       if ans>((o-1)*z+(z-o+1)+l) then ans:=o*(z-1)+l;
       if ans>((z-o)*z+(o+1)+l) then ans:=(z-o)*(z-1)+l;
      end;
      f:=d1;
     end;
    end;
     begin
      if (x=a1) and (y=a2) then inc(l1);
      if (x=c1) and (y=c2) then begin inc(l2); o:=z; end;
      if f[x+1,y]=1 then begin f[x+1,y]:=2; find2(x+1,y,z+1,o); f[x+1,y]:=1; end;
      if f[x-1,y]=1 then begin f[x-1,y]:=2; find2(x-1,y,z+1,o); f[x-1,y]:=1; end;
      if f[x,y+1]=1 then begin f[x,y+1]:=2; find2(x,y+1,z+1,o); f[x,y+1]:=1; end;
      if f[x,y-1]=1 then begin f[x,y-1]:=2; find2(x,y-1,z+1,o); f[x,y-1]:=1; end;
      if (x=a1) and (y=a2) then dec(l1);
      if (x=c1) and (y=c2) then begin dec(l2); o:=0; end;
     end;
   end;
procedure find(a1,a2,b1,b2,c1,c2:longint);
   begin
    f:=d;
    f[b1,b2]:=2;
    if (b1-c1)*(b1-c1)+(b2-c2)*(b2-c2)=1 then
     begin
      f[c1,c2]:=2;
      find1(c1,c2,1);
      f[c1,c2]:=1;
     end;
    l1:=0; l2:=0;
    find2(b1,b2,0,0);
   end;
begin
 assign(input,'puzzle.in'); reset(input);
 assign(output,'puzzle.out'); rewrite(output);
 readln(n,m,q);
 for i:=1 to n do
  begin
   for j:=1 to m do begin read(d[i,j]); end;
   readln;
  end;
 for i:=1 to q do
  begin
   readln(a1,a2,b1,b2,c1,c2);
   ans:=2147483647;
   find(a1,a2,b1,b2,c1,c2);
   if ans=2147483647 then writeln(-1) else
   writeln(ans);
  end;
 close(input); close(output);
end.
