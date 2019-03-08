program t2002_4;
const maxn=50;
type node=record
         x,y:integer;
     end;
     arr=array[1..maxn]of node;

var n,k,i,j,p,last,last1,minx,miny,maxx,maxy:integer;
    a,b:arr;
    area,sub1,sub2,sub3:longint;

procedure sort(var b:arr;first,last,flag:integer);
var i,j:integer;temp:node;
begin
    if flag=1 then  {sort as x}
       for i:=first to last-1 do
          for j:=i+1 to last do begin
             if b[i].x>b[j].x then begin
               temp:=b[i];b[i]:=b[j];b[j]:=temp;end
          end
    else
       for i:=1 to n-1 do
          for j:=i+1 to n do begin
             if b[i].y>b[j].y then begin
                temp:=b[i];b[i]:=b[j];b[j]:=temp;end
          end;
end;

function block(a:arr;first,last,flag:integer):longint;
var i,min,max:integer;
begin
    if flag=1 then begin
       min:=maxint;max:=-maxint;
       for i:=first to last do begin
          if a[i].y<min then min:=a[i].y;
          if a[i].y>max then max:=a[i].y;
       end;
       block:=(a[last].x-a[first].x)*(max-min);
     end
    else begin
       min:=maxint;max:=-maxint;
       for i:=first to last do begin
          if a[i].x<min then min:=a[i].x;
          if a[i].x>max then max:=a[i].x;
       end;
       block:=(a[last].y-a[first].y)*(max-min);
    end;
end;

begin
    assign(input,'d.in');
    reset(input);
    readln(n,k);
    for i:=1 to n do readln(a[i].x,a[i].y);
    close(input);
    assign(output,'d.out');
    rewrite(output);
    if k=1 then begin
         minx:=maxint;maxx:=-maxint;
         miny:=maxint;maxy:=-maxint;
         for i:=1 to n do begin
             if a[i].x<minx then minx:=a[i].x;
             if a[i].x>maxx then maxx:=a[i].x;
             if a[i].y<miny then miny:=a[i].y;
             if a[i].y>maxy then maxy:=a[i].y;
         end;
         area:=(maxx-minx)*(maxy-miny);
      end
    else if k=2 then begin
           sort(a,1,n,1);
           area:=maxint;
           last:=n-1;
           while a[last].x=a[last+1].x do last:=last-1;
           while i<=last do begin
               while a[i].x=a[i+1].x do i:=i+1;
               sub1:=block(a,1,i,1);
               sub2:=block(a,i+1,n,1);
               if sub1+sub2<area then BEGIN area:=sub1+sub2;END;
               i:=i+1;
           end;
           sort(a,1,n,2);
           last:=n-1;
           while a[last].y=a[last+1].y do last:=last-1;
           i:=1;
           while a[i].y=a[i+1].y do i:=i+1;
           while i<=last do begin
               sub1:=block(a,1,i,2);
               sub2:=block(a,i+1,n,2);
               if sub1+sub2<area then area:=sub1+sub2;
               i:=i+1;
               while a[i].y=a[i+1].y do i:=i+1;
           end;
      end
    else if k=3 then begin
          area:=maxint;
  {No.1}
                   {1    1    1}
                   {1    1    1}
          sort(a,1,n,1);
          last:=n-1;
          while (last>0) and (a[last].x=a[last+1].x) do last:=last-1;
          last1:=last-1;
          while (last1>0) and (a[last1].x=a[last1+1].x) do last1:=last1-1;
          if last1>=1 then begin
              i:=1;
              while a[i].x=a[i+1].x do i:=i+1;
              while i<=last1 do begin
                  sub1:=block(a,1,i,1);
                  j:=i+1;
                  while a[j].x=a[j+1].x do j:=j+1;
                  while j<=last do begin
                      sub2:=block(a,i+1,j,1);
                      sub3:=block(a,j+1,n,1);
                      if sub1+sub2+sub3<area then area:=sub1+sub2+sub3;
                      j:=j+1;
                      while a[j].x=a[j+1].x do j:=j+1;
                  end;
                  i:=i+1;
                  while a[i].x=a[i+1].x do i:=i+1;
              end;
          end;
   {No.2}
                {1     --}
                {1     --}
          last1:=n-1;
          while (last1>0) and (a[last1].y=a[last1+1].y) do last1:=last1-1;
          last1:=last1-1;
          while (last1>0) and (a[last1].x=a[last1+1].x) do last1:=last1-1;
          if last1>=1 then begin
              i:=1;
              while a[i].x=a[i+1].x do i:=i+1;
              b:=a;
              while (i<=last1) do begin
                  sub1:=block(b,1,i,1);
                  j:=i+1;
                  sort(b,j,n,2);
                  last:=n-1;
                  while b[last].y=b[last+1].y do last:=last-1;
                  p:=j;
                  while b[p].y=b[p+1].y do p:=p+1;
                  while p<=last do begin
                      sub2:=block(b,j,p,2);
                      sub3:=block(b,p+1,n,2);
                      if sub1+sub2+sub3<area then area:=sub1+sub2+sub3;
                      p:=p+1;
                      while b[p].y=b[p+1].y do p:=p+1;
                  end;
                  b:=a;
                  i:=i+1;
                  while a[i].x=a[i+1].x do i:=i+1;
              end;
          end;
  {No.3}
                {-}
                {-}
                {-}
          sort(a,1,n,2);
          last:=n-1;
          while (last>0) and (a[last].y=a[last+1].y) do last:=last-1;
          last1:=last-1;
          while (last1>0) and (a[last1].y=a[last1+1].y) do last1:=last1-1;
          if last1>=1 then begin
              i:=1;
              while a[i].y=a[i+1].y do i:=i+1;
              while i<=last1 do begin
                  sub1:=block(a,1,i,2);
                  j:=i+1;
                  while a[j].y=a[j+1].y do j:=j+1;
                  while j<=last do begin
                      sub2:=block(a,i+1,j,2);
                      sub3:=block(a,j+1,n,2);
                      if sub1+sub2+sub3<area then area:=sub1+sub2+sub3;
                      j:=j+1;
                      while a[j].y=a[j+1].y do j:=j+1;
                  end;
                  i:=i+1;
                  while a[i].y=a[i+1].y do i:=i+1;
              end;
          end;
   {No.4}
             {-----}
             {1   1}
          last1:=n-1;
          while (last1>0) and (a[last1].x=a[last1+1].x) do last1:=last1-1;
          last1:=last1-1;
          while (last1>0) and (a[last1].y=a[last1+1].y) do last1:=last1-1;
          if last1>=1 then begin
              i:=1;
              while a[i].y=a[i+1].y do i:=i+1;
              b:=a;
              while (i<=last1) do begin
                  sub1:=block(b,1,i,2);
                  j:=i+1;
                  sort(b,j,n,1);
                  last:=n-1;
                  while b[last].x=b[last+1].x do last:=last-1;
                  p:=j;
                  while b[p].x=b[p+1].x do p:=p+1;
                  while p<=last do begin
                      sub2:=block(b,j,p,1);
                      sub3:=block(b,p+1,n,1);
                      if sub1+sub2+sub3<area then area:=sub1+sub2+sub3;
                      p:=p+1;
                      while b[p].x=b[p+1].x do p:=p+1;
                  end;
                  b:=a;
                  i:=i+1;
                  while a[i].y=a[i+1].y do i:=i+1;
              end;
          end;
   {No.5}
          {---     1}
          {---     1}
          sort(a,1,n,1);
          last:=2;
          while (last<=n) and (a[last].y=a[last-1].y) do last:=last+1;
          while (last<=n-1) and (a[last].x=a[last+1].x) do last:=last+1;
          if last<=n-1 then begin
              i:=n;
              while a[i].x=a[i-1].x do i:=i-1;
              b:=a;
              while i>last do begin
                  sub3:=block(b,i,n,1);
                  sort(b,1,i-1,2);
                  last1:=i-2;
                  while (last1>0) and (b[last1].y=b[last1+1].y) do last1:=last1-1;
                  j:=1;
                  while a[j].y=a[j+1].y do j:=j+1;
                  while j<=last1 do begin
                       sub1:=block(b,1,j,2);
                       sub2:=block(b,j+1,last1,2);
                       if sub1+sub2+sub3<area then area:=sub1+sub2+sub3;
                       j:=j+1;
                       while a[j].y=a[j+1].y do j:=j+1;
                  end;
                  b:=a;
                  i:=i-1;
                  while a[i].x=a[i-1].x do i:=i-1;
              end;
          end;
  {No.6}
                 {1    1}
                 {------}
          sort(a,1,n,2);
          last:=2;
          while (last<=n) and (a[last].x=a[last-1].x) do last:=last+1;
          while (last<=n-1) and (a[last].x=a[last+1].x) do last:=last+1;
          if last<=n-1 then begin
              i:=n;
              while (i>last) and (a[i].y=a[i-1].y) do i:=i-1;
              b:=a;
              while i>last do begin
                  sub3:=block(b,i,n,2);
                  sort(b,1,i-1,1);
                  last1:=i-2;
                  while (last1>0) and (b[last1].x=b[last1+1].x) do last1:=last1-1;
                  j:=1;
                  while a[j].x=a[j+1].x do j:=j+1;
                  while j<=last1 do begin
                       sub1:=block(b,1,j,1);
                       sub2:=block(b,j+1,last1,1);
                       if sub1+sub2+sub3<area then area:=sub1+sub2+sub3;
                       j:=j+1;
                       while a[j].x=a[j+1].x do j:=j+1;
                  end;
                  b:=a;
                  i:=i-1;
                  while a[i].y=a[i-1].y do i:=i-1;
              end;
          end;
      end  {k=3}
    else if k=4 then begin
           writeln('To Complex,I failed at that point!');
      end
    else begin
        writeln('Error K input! k must in [1..4]');
        halt;
    end;
    writeln(area);
    close(output);
end.
