var a,s:array[0..31,0..31] of longint;
    n,m,p,i,j,l,x1,x2,x3,y1,y2,y3,op,ed,z,c:longint;
    g,h,x,y,deep,pre,pe.pr:array[0..1000] of longint;
    b:boolean;

 function sb:boolean;
 begin
 if s[x2,y2+1]=6 then exit(true);
  if s[x2,y2-1]=6 then exit(true);
   if s[x2+1,y2]=6 then exit(true);
    if s[x2-1,y2]=6 then exit(true);
    exit(false);
    end;

 procedure dfs;
 var q,w,e,r:longint;
 begin
 if b then exit;
 inc(op);
 e:=op;
 q:=x[op];w:=y[op];
 if s[q,w+1]=4 then begin inc(op);x[op]:=q;y[op]:=w+1;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q-1,w]=4 then begin inc(op);x[op]:=q-1;y[op]:=w;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q+1,w]=4 then begin inc(op);x[op]:=q+1;y[op]:=w;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q,w-1]=4 then begin inc(op);x[op]:=q;y[op]:=w-1;deep[op]:=deep[e]+1;b:=true;exit;end;
 if(s[q,w+1]=1) then
   begin inc(ed);x[ed]:=q;y[ed]:=w+1;s[q,w+1]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if(s[q-1,w]=1) then
   begin inc(ed);x[ed]:=q-1;y[ed]:=w;s[q-1,w]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if(s[q+1,w]=1) then
   begin inc(ed);x[ed]:=q+1;y[ed]:=w;s[q+1,w]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if(s[q,w-1]=1) then
   begin inc(ed);x[ed]:=q;y[ed]:=w-1;s[q,w-1]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if op<ed then dfs;
 end;

 procedure df;
 var q,w,e,r:longint;
 begin
 if b then exit;
 inc(op);e:=op;
 q:=x[op];w:=y[op];
 if s[q,w+1]=6 then begin pr[op+1]:=e;inc(op);x[op]:=q;y[op]:=w+1;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q-1,w]=6 then begin pr[op+1]:=e;inc(op);x[op]:=q-1;y[op]:=w;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q+1,w]=6 then begin pr[op+1]:=e;inc(op);x[op]:=q+1;y[op]:=w;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q,w-1]=6 then begin pr[op+1]:=e;inc(op);x[op]:=q;y[op]:=w-1;deep[op]:=deep[e]+1;b:=true;exit;end;
if(s[q,w+1]=1) then
  begin inc(ed);x[ed]:=q;y[ed]:=w+1;s[q,w+1]:=0;
  deep[ed]:=deep[op]+1;pr[ed]:=op;end;

 if(s[q-1,w]=1) then
  begin inc(ed);x[ed]:=q-1;y[ed]:=w;s[q-1,w]:=0;
  deep[ed]:=deep[op]+1;pr[ed]:=op;end;

 if(s[q+1,w]=1)then
  begin inc(ed);x[ed]:=q+1;y[ed]:=w;s[q+1,w]:=0;
  deep[ed]:=deep[op]+1;pr[ed]:=op;end;

 if(s[q,w-1]=1) then
  begin inc(ed);x[ed]:=q;y[ed]:=w-1;s[q,w-1]:=0;
  deep[ed]:=deep[op]+1;pr[ed]:=op;end;

 if op<ed then df;
 end;


  procedure dfm;
 var q,w,e,r:longint;
 begin
 if b then exit;
 inc(op);
 e:=op;
 q:=x[op];w:=y[op];
 if s[q,w+1]=6 then begin inc(op);pre[op]:=e;x[op]:=q;y[op]:=w+1;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q-1,w]=6 then begin inc(op);pre[op]:=e;x[op]:=q-1;y[op]:=w;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q+1,w]=6 then begin inc(op);pre[op]:=e;x[op]:=q+1;y[op]:=w;deep[op]:=deep[e]+1;b:=true;exit;end;
 if s[q,w-1]=6 then begin inc(op);pre[op]:=e;x[op]:=q;y[op]:=w-1;deep[op]:=deep[e]+1;b:=true;exit;end;
 if(s[q,w+1]=1) then
   begin inc(ed);x[ed]:=q;y[ed]:=w+1;s[q,w+1]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if(s[q-1,w]=1) then
   begin inc(ed);x[ed]:=q-1;y[ed]:=w;s[q-1,w]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if(s[q+1,w]=1) then
   begin inc(ed);x[ed]:=q+1;y[ed]:=w;s[q+1,w]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if(s[q,w-1]=1) then
   begin inc(ed);x[ed]:=q;y[ed]:=w-1;s[q,w-1]:=0;
   deep[ed]:=deep[op]+1;pre[ed]:=op;end;
 if op<ed then dfs;
 end;

begin
 assign(input,'puzzle.in');reset(input);
 assign(output,'puzzle.out');rewrite(output);
 read(n,m,p);
 for i:=1 to n do
  for j:=1 to m do read(a[i,j]);

 for l:=1 to p do begin read(x1,y1,x2,y2,x3,y3);

  for i:=1 to n do
   for j:=1 to m do s[i,j]:=a[i,j];

    s[x1,y1]:=4;
    s[x2,y2]:=5;
    s[x3,y3]:=6;

   if (x2=x3)and(y2=y3) then writeln(0) else begin
    if sb then begin
    b:=false;
    op:=0;ed:=1;
    deep[1]:=1;
    x[1]:=x3;
    y[1]:=y3;
    dfs;
    if b=false then writeln(-1) else
    writeln(deep[op]);
      end
    else  begin

    b:=false;
    op:=0;ed:=1;
    deep[1]:=1;
    x[1]:=x2;
    y[1]:=y2;
    df;
    writeln(pr[op]);

   for i:=1 to n do
     for j:=1 to m do s[i,j]:=a[i,j];
    z:=pr[op];
    c:=z;
    write(c);
    for j:=1 to deep[z] do begin
    s[x[c],y[c]]:=0;
    c:=pre[c];end;
    ans:=deep[op];

    s[x1,y1]:=4;
    s[x2,y2]:=5;
    s[x3,y3]:=6;
    b:=false;
    op:=0;ed:=1;
    deep[1]:=1;
    x[1]:=x2;
    y[1]:=y2;
    dfm;
    if b then write(ans) else write(-1);



   end;
   end;
   end;
 close(input);
close(output);
 end.
