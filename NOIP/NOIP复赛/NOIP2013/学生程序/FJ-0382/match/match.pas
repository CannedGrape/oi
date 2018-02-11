program match;


var i,n,k,l:longint;
    c,d:array[-100..100100]of longint;
    a,b:array[-100..100100,0..1]of longint;
    flag,flag1,flag2:boolean;
    af,bf:array[-110..100100]of boolean;
    temp,s:longint;

procedure qsortc(l,r: longint);

  var i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=c[(l+r) div 2];
         repeat
           while c[i]<x do
            inc(i);
           while x<c[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           qsortc(l,j);
         if i<r then
           qsortc(i,r);
      end;

procedure qsortd(l,r: longint);

  var i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=d[(l+r) div 2];
         repeat
           while d[i]<x do
            inc(i);
           while x<d[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=d[i];
                d[i]:=d[j];
                d[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           qsortd(l,j);
         if i<r then
           qsortd(i,r);
      end;



{main}
begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
s:=0;
{duru}
readln(n);

for i:=1 to n do
  begin
    read(a[i,0]);
    c[i]:=a[i,0]
  end;


for i:=1 to n do
  begin
    read(b[i,0]);
    d[i]:=b[i,0];
  end;

{paixu}
qsortc(1,n);
qsortd(1,n);
                {zhidaozhebudouzhengchang}

for i:=1 to n do
  for k:=1 to n do
    begin
        flag1:=false; flag2:=false;
        if (c[i] = a[k,0]) and (a[k,1]=0) then begin a[k,1]:=i; flag1:=true; end;
        if (d[i] = b[k,0]) and (b[k,1]=0) then begin b[k,1]:=i; flag2:=true; end;
        if (flag1=true) and (flag2=true) then break;
    end;


for i:=1 to n do
    begin
        af[i]:=false;
        bf[i]:=false;
    end;


s:=0;
for i:=1 to n do
    begin
    flag:=false;
        if (a[i,1]=b[i,1])  then
             begin
                 af[i]:=true;
                 bf[i]:=true;
                 flag:=true;
             end
            else
                begin
                    for k:=1 to n do
                        begin
                            if flag=true then break;
                            if a[i,1]=b[k,1] then
                                             begin
                                              bf[i]:=true;
                                              af[i]:=true;
                                                  begin
                                                      temp:=b[i,1];
                                                      b[i,1]:=b[k,1];
                                                      b[k,1]:=temp;
                                                  end;
                                              s:=s+1;
                                              s:=s mod 99999997;
                                              break;
                                             end;

                        end;
                end;
        end;

write(s);
close(input);
close(output);

end.
