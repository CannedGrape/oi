{$R-,S-,Q-,I-}
const
        fin = 'cashier.in';
        fon = 'cashier.out';
        maxn = 100001;
        maxv = 1000000;
        nils = 0;
var
        key, pr, lc, rc, sum : array[0..maxn] of longint;
        x, n, rec, s, min, tot, total : longint;
        bufinput, bufoutput : array[0..4096 * 16] of char;
        next : boolean;

procedure insert(var node : longint);
var child : longint;
begin
  if node = nils then begin
     if rec = nils then begin
        inc(s); node := s;
     end else begin
        node := rec; rec := lc[rec];
     end;
     key[node] := x;
     pr[node] := random(maxv);
     lc[node] := nils;
     rc[node] := nils;
     sum[node] := 1;
     exit;
  end else if x < key[node] then begin
     insert(lc[node]);
     child := lc[node];
     if pr[child] < pr[node] then begin
        lc[node] := rc[child];
        rc[child] := node;
        sum[node] := sum[lc[node]] + sum[rc[node]] + 1;
        sum[child] := sum[lc[child]] + sum[rc[child]] + 1;
        node := child;
     end else inc(sum[node]);
  end else begin
     insert(rc[node]);
     child := rc[node];
     if pr[child] < pr[node] then begin
        rc[node] := lc[child];
        lc[child] := node;
        sum[node] := sum[lc[node]] + sum[rc[node]] + 1;
        sum[child] := sum[lc[child]] + sum[rc[child]] + 1;
        node := child;
     end else inc(sum[node]);
  end;
end;

procedure add(node : longint);
begin
  if node = nils then exit;
  inc(key[node], x);
  add(lc[node]);
  add(rc[node]);
end;

procedure delete(var node : longint);
var temp : longint;
begin
  if lc[node] = nils then
     if key[node] < min then begin
        inc(tot);
        dec(total);
        next := true;
        temp := node;
        node := rc[node];
        lc[temp] := rec;
        rec := temp;
     end else
  else begin
     delete(lc[node]);
     if next then dec(sum[node]);
  end;
end;

procedure find(node : longint);
begin
  if x <= sum[lc[node]] then find(lc[node])
  else if x > sum[lc[node]] + 1 then begin
    dec(x, sum[lc[node]] + 1);
    find(rc[node])
  end
  else writeln(key[node]);
end;

procedure main;
var i, root : longint;
    ch : char;
begin
  readln(n, min); root := 0;
  for i := 1 to n do begin
    readln(ch, x);
    case ch of
      'I' : if x >= min then begin
               insert(root); inc(total);
            end
            else inc(tot);
      'A' : add(root);
      'S' : begin
              x := - x;
              add(root);
              repeat
                next := false;
                if root <> nils then delete(root);
              until not next;
            end;
      'F' : begin
              x := total - x + 1;
              if x > 0 then find(root) else writeln(-1);
            end;
    end;
  end;
  writeln(tot);
end;

begin
  assign(input, fin); settextbuf(input, bufinput); reset(input);
  assign(output, fon); settextbuf(output, bufoutput); rewrite(output);
  main;
  close(input);
  close(output);
end.
