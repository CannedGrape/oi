program NOIP2003_1_Network;
  const
    maxn=200;maxp=200;
  var
    i,j,n,p,maxlayer:integer;
    w:array[0..maxp]of longint;
    start,terminal:array[0..maxp]of byte;
    u,c:array[0..maxn]of longint;
    layer:array[0..maxn]of byte;
    f1,f2:text;fn1,fn2,fileNo:string;
    flag:boolean;
  begin
    write('Input fileNo:');
    readln(fileNo);
    fn1:='network.in'+fileNo;
    fn2:='network.ou'+fileNo;
    assign(f1,fn1);reset(f1);
    assign(f2,fn2);rewrite(f2);
    readln(f1,n,p);
    for i:=1 to n do readln(f1,c[i],u[i]);
    fillchar(layer,sizeof(layer),0);
    for i:=1 to p do begin
      readln(f1,start[i],terminal[i],w[i]);
      layer[terminal[i]]:=layer[start[i]]+1;
    end;
    close(f1);
    maxlayer:=layer[terminal[p]];
    for i:=1 to n do
      if layer[i]>0 then begin
        for j:=1 to p do
          if (terminal[j]=i) and (c[start[j]]>0)
            then c[i]:=c[i]+w[j]*c[start[j]];
        c[i]:=c[i]-u[i];
      end;
    flag:=true;
    for i:=1 to n do
      if (layer[i]=maxlayer) and (c[i]>0) then begin
        writeln(f2,i,' ',c[i]);
        flag:=false;
      end;
    if flag then writeln(f2,'NULL');
    close(f2);
  end.