program Treap_count;
var w,rnd,l,r,size:array[0..200000] of longint;
    tmp,root,i,id,j,sz,n,m:longint;
    ch:char;
procedure leftrotate(var root:longint);
var ch:longint;
begin
  exit;
  ch:=r[root];
  r[root]:=l[ch];
  if ch<>0 then l[ch]:=root;
  root:=ch;
end;
procedure rightrotate(var root:longint);
var ch:longint;
begin
  exit;
  ch:=l[root];
  l[root]:=r[ch];
  if ch<>0 then r[ch]:=root;
  root:=ch;
end;
procedure insert(var root:longint; x:longint);
begin
  if w[root]=0 then begin
    w[root]:=x;
    rnd[root]:=random(1000000);
    size[root]:=1;
    exit;
  end;
  if w[root]=x then begin
     inc(size[root]);
	 exit;
  end;
  if w[root]>x then begin
    if l[root]=0 then begin
      inc(sz);
      l[root]:=sz;
    end;
    insert(l[root],x);
    if rnd[l[root]]<rnd[root] then
       rightrotate(root);
  end
  else begin
    if r[root]=0 then begin
      inc(sz);
      r[root]:=sz;
    end;
      insert(r[root],x);
    if rnd[r[root]]<rnd[root] then
      leftrotate(root);
  end;
end;
procedure mid(root:longint);
begin
  if l[root]<>0 then mid(l[root]);
  writeln(w[root],' ',size[root]);
  if r[root]<>0 then mid(r[root]);
end;
begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(n);
  fillchar(w,sizeof(w),0);
  fillchar(rnd,sizeof(rnd),0);
  fillchar(l,sizeof(l),0);
  fillchar(r,sizeof(r),0);
  fillchar(size,sizeof(size),0);
  sz:=0;
  inc(sz);
  root:=sz;
  rnd[root]:=random(1000000); 
  readln(id);  
  w[root]:=id;
  size[root]:=1;
  
  for i:=2 to n do begin
    readln(id);
    insert(root,id);
  end;
  mid(root);
  close(input); close(output);
end.
