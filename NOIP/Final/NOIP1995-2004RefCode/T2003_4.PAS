program t2003_4(input,output);{Epidemic Control}
const maxn=300;
type l_in=^in_node; {p lines of infect roads}
     in_node=record
         a,b:integer;
         next:l_in;
     end;
     point=^node;    { sub tree nodes}
     node=record
        v:integer;{first is the number of subs;others are the name of the sub}
        next:point;
     end;

var
    h1,p1,p2:l_in;
    n,p:integer;
    h2,t2:integer;{worksheet point}
    f:array[1..maxn] of integer; {worksheet}
    fh,ft:integer;
    g:array[1..maxn] of point;
    gh,gp,gq:point;
    i:integer;
    r,s:integer;

procedure de(gd:integer);
var gk,gm:point;
begin
    gk:=g[gd];gm:=gk^.next;
    while gm<>nil do begin
        gk^.next:=gm^.next;dispose(gm);gm:=gk^.next;
    end;
    gk^.v:=0;
end;

procedure merge(bin,gd:integer);
var gk,gm:point;
begin
    g[bin]^.v:=g[bin]^.v+g[gd]^.v;
    gk:=g[bin];gm:=gk^.next;
    while gm<>nil do begin gm:=gm^.next;gk:=gk^.next;end;
    gk^.next:=g[gd]^.next;
    g[gd]^.next:=nil;
    g[gd]^.v:=0;
end;
function big(a,b:integer):boolean;
var max1,max2:integer;gp:point;
begin
    if g[a]^.v>g[b]^.v then
        big:=true
    else if g[a]^.v<g[b]^.v then
        big:=false
    else begin
        max1:=0;
        gp:=g[a]^.next;
        while gp<>nil do begin
          {  if g[gp^.v]^.v>max1 then max1:=g[gp^.v]^.v;}
            max1:=max1+g[gp^.v]^.v;
            gp:=gp^.next;
        end;
        max2:=0;
        gp:=g[b]^.next;
        while gp<>nil do begin
          {  if g[gp^.v]^.v>max2 then max2:=g[gp^.v]^.v; }
            max2:=max2+g[gp^.v]^.v;
            gp:=gp^.next;
        end;
        if max1>max2 then big:=true
        else big:=false;
    end;
end;

function count(i:integer):integer;
var gp,gq:point;
    bin,dele,gt:integer;
    c:integer;
    csum:integer;
    ggg:point;
begin
    gp:=g[i]^.next;
    if gp=nil then count:=0
    else begin
        gq:=gp^.next;
        if gq=nil then count:=0
        else begin
             c:=1;
             if big(gq^.v,gp^.v) then
                    begin bin:=gp^.v;dele:=gq^.v;end
             else
                    begin bin:=gq^.v;dele:=gp^.v;end;
             gq:=gq^.next;
             while gq<>nil do begin
                 if big(dele,gq^.v) then gt:=gq^.v
                   else begin gt:=dele;dele:=gq^.v;end;
                 if g[gt]^.v>0 then
                      merge(bin,gt);
                 c:=c+1;
                 gq:=gq^.next;
             end;
             de(dele);
{             writeln;
             writeln('c=',c,' bin=',bin,' dele=',dele);
             ggg:=g[bin];
             while ggg<>nil do begin write(ggg^.v,' ');ggg:=ggg^.next;end;
             writeln;
}
             csum:=count(bin);
{             writeln('count=',c+csum);}
             count:=c+csum;

         end;
    end;
end;

begin
    assign(input,'epidemic.in');
    reset(input);
    readln(n,p);
    i:=1;new(h1);h1^.next:=nil;p1:=h1;
    while i<=p do begin
       new(p2);
       readln(r,s);
       p2^.a:=r;p2^.b:=s;
       p2^.next:=nil;
       p1^.next:=p2;
       p1:=p2;
       i:=i+1;
    end;
    close(input);
    assign(output,'epidemic.out');
    rewrite(output);

    for i:=2 to n do f[i]:=0;
    f[1]:=1;
    for i:=1 to n do begin new(g[i]);g[i]^.next:=nil; g[i]^.v:=0;end;
    fh:=1;ft:=2;
    while f[fh]<>0 do begin
       p1:=h1;p2:=p1^.next;
       while (p2<>nil) do begin
           while (p2<>nil) and (p2^.a<>f[fh]) and (p2^.b<>f[fh]) do
               begin p2:=p2^.next;p1:=P1^.next;end;
           if p2<>nil then begin
              if p2^.a=f[fh] then r:=p2^.b
                  else r:=p2^.a;
              f[ft]:=r;ft:=ft+1;
              gp:=g[f[fh]];gq:=gp^.next;
              while gq<>nil do begin gp:=gp^.next;gq:=gq^.next;end;
              new(gq);
              g[f[fh]]^.v:=g[f[fh]]^.v+1;
              gq^.v:=r;gq^.next:=nil;
              gp^.next:=gq;
              p1^.next:=p2^.next;
              dispose(p2);
              p2:=p1^.next;
           end;
       end;
       fh:=fh+1;
    end;
{
for fh:=1 to n do write(f[fh],' ');writeln;
for fh:=1 to n do begin
    gp:=g[fh];
    write(gp^.v);
    gp:=gp^.next;
    while gp<>nil do begin
        write(' ',gp^.v);
        gp:=gp^.next;
    end;
    writeln;
end;
}

    writeln(1+count(1));
    close(output);
end.
