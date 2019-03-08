program t2003_1;
const maxn=200;
      maxp=20000;
var n,p,i,j,maxlayer:integer;
    c,u:array[0..maxn]of longint;
    sta,tem,w:array[0..maxp]of integer;
    layer:array[0..maxn]of integer;
    find:boolean;

begin
    assign(input,'network.in');
    reset(input);
    readln(n,p);
    for i:=1 to n do layer[i]:=0;
    for i:=1 to n do
       readln(c[i],u[i]);
    for i:=1 to p do begin
       readln(sta[i],tem[i],w[i]);
       layer[tem[i]]:=layer[sta[i]]+1;
    end;
    close(input);
    maxlayer:=0;
    for i:=1 to n do
       if maxlayer<layer[i] then
          maxlayer:=layer[i];
    for i:=1 to n do begin
      if layer[i]>0 then begin
         for j:=1 to p do
            if (tem[j]=i) and (c[sta[j]]>0) then
               c[i]:=c[i]+w[j]*c[sta[j]];
         c[i]:=c[i]-u[i];
      end;
    end;
    find:=false;
    assign(output,'network.out');
    rewrite(output);
    for i:=1 to n do
      if (layer[i]=maxlayer) and (c[i]>0) then
         begin find:=true;writeln(i,' ',c[i]);end;
    if not find then writeln('NULL');
    close(output);
end.
