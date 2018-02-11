program cashier;
type
  pointer=longint;
  node=record
         l,r:pointer;
         num:longint;
       end;
var
  ch:char;
  f,o:text;
  head:pointer;
  m:array[1..600001] of node;
  i,k,n,delta,mem,min,total:longint;

function init(l,r:longint):pointer;
var
  p:pointer;
begin
  inc(mem);p:=mem;m[p].num:=0;
  if l=r then
  begin
    m[p].l:=0;
    m[p].r:=0;
  end
  else
  begin
    m[p].l:=init(l,(l+r) div 2);
    m[p].r:=init((l+r) div 2+1,r);
  end;
  init:=p;
end;

procedure insert(now:pointer;a,b,c:longint);
begin
  inc(m[now].num);
  if a=b then exit;
  if c<=(a+b) div 2 then
    insert(m[now].l,a,(a+b) div 2,c)
  else
    insert(m[now].r,(a+b) div 2+1,b,c);
end;

procedure clear(now:pointer;a,b,c:longint);
begin
  if c<0 then exit;
  if a=b then m[now].num:=0;
  if m[now].num=0 then exit;
  if c<=(a+b) div 2 then
  begin
    clear(m[now].l,a,(a+b) div 2,c);
  end
  else
  begin
    clear(m[now].l,a,(a+b) div 2,(a+b) div 2);
    clear(m[now].r,(a+b) div 2+1,b,c);
  end;
  m[now].num:=m[m[now].l].num+m[m[now].r].num;
end;

function find(now:pointer;a,b,c:longint):longint;
begin
  if a=b then
  begin
    find:=a;
    exit;
  end;
  if m[m[now].l].num>=c then
    find:=find(m[now].l,a,(a+b) div 2,c)
  else
    find:=find(m[now].r,(a+b) div 2+1,b,c-m[m[now].l].num);
end;

begin
  mem:=0;
  head:=init(0,300000);
  assign(f,'cashier.in');
  reset(f);
  assign(o,'cashier.out');
  rewrite(o);
  readln(f,n,min);
  delta:=100000;total:=0;
  for i:=1 to n do
  begin
    read(f,ch);
    case ch of
      'I':
      begin
        readln(f,k);
        if k>=min then
          insert(head,0,300000,k+delta)
        else
          inc(total);
      end;
      'A':
      begin
        readln(f,k);
        dec(delta,k);
        if k<0 then
        begin
          inc(total,m[head].num);
          clear(head,0,300000,min+delta-1);
          dec(total,m[head].num);
        end;
      end;
      'S':
      begin
        readln(f,k);
        inc(delta,k);
        if k>0 then
        begin
          inc(total,m[head].num);
          clear(head,0,300000,min+delta-1);
          dec(total,m[head].num);
        end;
      end;
      'F':
      begin
        readln(f,k);
        if k>m[head].num then
          writeln(o,-1)
        else
          writeln(o,find(head,0,300000,m[head].num-k+1)-delta);
      end;
    end;
  end;
  writeln(o,total);
  close(o);
  close(f);
end.
