# yaml-sql

Zed extension scaffold for highlighting SQL embedded inside YAML values.

## Behavior

The extension injects SQL into YAML values when either of these patterns is
present:

```yaml
#language=sql
query: SELECT * FROM users
```

```yaml
sql_query: SELECT * FROM users
```

It targets:

- plain YAML scalars such as `sql_query: SELECT * FROM users`
- block scalars such as `sql_query: |`

Quoted YAML scalars are intentionally excluded in this first pass because the
YAML grammar exposes the quote delimiters as part of the scalar range, which
would pollute the injected SQL region.

## Structure

- `languages/yaml`: copied from Zed's current built-in YAML grammar queries,
  with an augmented `injections.scm`
- `languages/embedded-sql`: minimal SQL language metadata and highlighting so
  the embedded regions work without requiring the standalone SQL extension

## Local Development

1. Open Zed.
2. Run `zed: install dev extension`.
3. Choose this directory.
4. Open [examples/sql-in-yaml.yaml](examples/sql-in-yaml.yaml).
5. If the buffer still uses the built-in YAML language, select `YAML SQL`
   from the language picker.

## Notes

- `extension.toml` currently uses a placeholder `repository` URL.
- The key-name heuristic matches keys where `sql` appears as its own token, for
  example `sql`, `sql_query`, `query_sql`, or `foo-sql-bar`.
