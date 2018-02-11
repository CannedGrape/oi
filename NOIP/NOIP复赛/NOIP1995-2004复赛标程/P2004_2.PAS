program peanuts; 				
type mytype=record				
            x,y,d:integer;				
           end;				
var time,all,num,i,j,m,n,k,u,v,z:integer;				
    q:array[1..400] of mytype;				
    t:mytype;				
begin				
  all:=0;				
  assign(input,'peanuts.in');				
  reset(input);				
  readln(m,n,k);				
  for i:=1 to m do				
  begin				
    for j:=1 to n do				
    begin				
      read(u);				
      if u>0 then				
       begin				
         inc(all);				
         q[all].x:=i;q[all].y:=j;q[all].d:=u;				
         if all>1 then				
         begin				
           v:=1;				
           while q[v].d>u do inc(v);				
           t:=q[all];				
           for z:=all downto v+1 do q[z]:=q[z-1];				
           q[v]:=t;				
        end;				
       end;				
    end;				
    readln;				
  end;				
  close(input);				
num:=0;time:=0;u:=0;v:=q[1].y;				
  for i:=1 to all do				
  begin				
    if time+abs(q[i].x-u)+abs(q[i].y-v)+1+q[i].x<=k				
       then begin				
               inc(num,q[i].d);				
               time:=time+abs(q[i].x-u)+abs(q[i].y-v)+1;				
               u:=q[I].x;v:=q[I].y;				
             end				
       else break;				
  end;				
  assign(output,'peanuts.out');				
  rewrite(output);				
  writeln(num);				
  close(output);				
end.				
