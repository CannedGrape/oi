
program p01_3(input,output);{ÏÈÐòÅÅÁÐ  LNR & LRN => NLR}
const maxn=8;
type point=^tree;
     tree=record
         root:char;
         left,right:point;
     end;
var head:point;zx,hx:STRING;
    i:integer;

FUNCTION gen(z1,z2,h1,h2:integer):POINT;
var p:point;i,j,min1,min2,max1,max2,m:integer;
begin
     if z1>z2 then gen:=nil
       else
         begin
              new(p);
              p^.root:=hx[h2];
                  WRITE(P^.ROOT);
              for i:=z1 to z2 do
                if zx[i]=hx[h2] then begin m:=i;break;end;
                   { WRITELN('m=',M);}
              min1:=maxint;max1:=0;
              for i:=z1 to m-1 do
                 for j:=h1 to h2 do
                    if zx[i]=hx[j] then
                     begin if j<min1 then min1:=j;
                           if j>max1 then max1:=j;end;
                   
              min2:=maxint;max2:=0;
              for i:=m+1 to z2 do
                 for j:=h1 to h2 do
                    if zx[i]=hx[j] then
                     begin if j<min2 then min2:=j;
                           if j>max2 then max2:=j;end;
         
              IF (Z1<=m-1) and (min1<=max1) then
                   p^.left:=gen(z1,m-1,min1,max1)
              else p^.left:=nil;
              IF (m+1<=Z2) and (min2<=max2) then
                   p^.right:=gen(m+1,z2,min2,max2)
              else p^.right:=nil;
         end;

end;



begin
     assign(input,'nlr.in');
     reset(input);
     READLN(ZX);READLN(HX);
     close(input);
     assign(output,'nlr.out');
     rewrite(output);
     HEAD:=gen(1,lenGTH(ZX),1,lenGTH(HX) );
     writeln;
     close(output);
end.

