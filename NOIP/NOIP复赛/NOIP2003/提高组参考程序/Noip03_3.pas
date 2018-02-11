{$N+}
program NOIP2003_3_Tree;
  const
    maxn=30;
  var
    i,j,n,d:byte;
    a:array[1..maxn]of byte;
    value:array[1..maxn,1..maxn]of comp;
    root:array[1..maxn,1..maxn]of byte;
    s,temp:comp;
    f1,f2:text;fn1,fn2,fileNo:string;
  procedure preorder(p1,p2:byte);
    begin
      if p2>=p1 then begin
        write(f2,root[p1,p2],' ');
        preorder(p1,root[p1,p2]-1);
        preorder(root[p1,p2]+1,p2);
      end;
    end;
  begin
    write('Input fileNo:');readln(fileNo);
    fn1:='tree.in'+fileNo;fn2:='tree.ou'+fileNo;
    assign(f1,fn1);reset(f1);
    assign(f2,fn2);rewrite(f2);
    readln(f1,n);
    for i:=1 to n do read(f1,a[i]);
    close(f1);
    fillchar(value,sizeof(value),0);
    for i:=1 to n do begin
      value[i,i]:=a[i];
      root[i,i]:=i;
    end;
    for i:=1 to n-1 do begin
      value[i,i+1]:=a[i]+a[i+1];
      root[i,i+1]:=i;
    end;
    for d:=2 to n-1 do begin
      for i:=1 to n-d do begin
        s:=value[i,i]+value[i+1,i+d];
        root[i,i+d]:=i;
        for j:=1 to d do begin
          temp:=value[i+j,i+j]+value[i,i+j-1]*value[i+j+1,i+d];
          if temp>s then begin
            s:=temp;root[i,i+d]:=i+j;
          end;
        end;
        temp:=value[i,i+d-1]+value[i+d,i+d];
        if temp>s then begin
          s:=temp;root[i,i+d]:=i+d+1;
        end;
        value[i,i+d]:=s;
      end;
    end;
    writeln(f2,value[1,n]:0:0);
    preorder(1,n);
    close(f2);
  end.