program p2000_2(input,output);{税收与补贴问题 Revenue or allowance}
const m=100;
type point=^node;
     node=record
         price:longint;
         sale:longint;
         next:point;
     end;
var head,tail,p,q:point;
    pz,sz,pc,sc,si,pi,d,i,k:longint;
    min,max,v:real;
    b1,b2,b:longint;

begin
     assign(input,'2.in');reset(input);
     readln(pz);
     readln(pc,sc);
     new(p);head:=p;
          p^.price:=pc;p^.sale:=sc;p^.next:=nil;
     readln(pi,si);
     while pi<>-1 do begin
          for i:=1 to pi-p^.price do begin
              new(q);
              q^.price:=p^.price+1;
              q^.sale:=p^.sale-(p^.sale-si) div (pi-p^.price) ;
              if q^.price=pz then sz:=q^.sale;
              q^.next:=nil;
              p^.next:=q;
              p:=q;
          end;
          readln(pi,si);
     end;
     readln(d);i:=p^.price;si:=p^.sale;
     close(input);
     while si>d do begin
         i:=i+1;
         si:=si-d;
         new(q);
         q^.price:=i;
         q^.sale:=si;
         if q^.price=pz then sz:=q^.sale;
         q^.next:=nil;
         p^.next:=q;
         p:=q;
     end;
     p:=head;max:=-1e20;min:=1e20;
     while p<>nil do begin

          if sz>p^.sale then begin
                  v:=((p^.price-pc)*p^.sale-(pz-pc)*sz)/(sz-p^.sale);
                  if v>max then max:=v;
              end
          else if sz<p^.sale then begin
                  v:=((p^.price-pc)*p^.sale-(pz-pc)*sz)/(sz-p^.sale);
                  if v<min then min:=v;
          end;
          p:=p^.next;
     end;
     b1:=trunc(max)-1;
     while b1<max do b1:=b1+1;
     b2:=trunc(min)+1;
     while b2>min do b2:=b2-1;
     assign(output,'2.out');
     rewrite(output);
     if b1<=b2 then begin
           if (b1>=0) and (b2>=0) then writeln(b1)
           else if (b1<0) and (b2<0) then writeln(b2)
           else writeln(0);
        end
     else writeln('NO SOLUTION');
     close(output);
end.


