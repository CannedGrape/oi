type
  zz=record
       u:longint;
       f:boolean;
     end;
var
  n,m,q,i,j,t,w,x1,y1:longint;
  x,y,z:array[1..100000]of longint;
  zhong:array[1..10000,1..10000]of zz;
begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input); rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do
      begin
        zhong[i,j].u:=-2; zhong[i,j].f:=true;
        zhong[j,i].u:=-2; zhong[j,i].f:=true;
      end;
  for i:=1 to m do
    begin
      read(x[i],y[i],z[i]);
      if zhong[x[i],y[i]].u<z[i] then
          begin
             zhong[x[i],y[i]].u:=z[i];
             zhong[y[i],x[i]].u:=z[i];
          end;
    end;  readln(q);
  for i:=1 to q do
    begin
      read(x1,y1);
      if zhong[x1,y1].f then
          begin
            for j:=1 to n do
              if (zhong[x1,j].u<>-2)and(zhong[j,y1].u<>-2)and(j<>x1)and(j<>y1) then
                  begin
                    if zhong[x1,j].u<zhong[j,y1].u then w:=zhong[x1,j].u
                      else w:=zhong[j,y1].u;
                    if zhong[x1,y1].u<w then
                        begin
                          zhong[x1,y1].u:=w;  zhong[y1,x1].u:=w;
                        end;
                  end;
            if zhong[x1,y1].u=-2 then
                begin
                  zhong[x1,y1].u:=-1; zhong[x1,y1].f:=false;
                  zhong[y1,x1].u:=-1; zhong[y1,x1].f:=false;
                end;
          end;
      writeln(zhong[x1,y1].u);
    end;
  close(input); close(output);
end.
