((comment) @injection.content
  (#set! injection.language "comment"))

; GitHub actions: JavaScript for workflow scripting (inline and block)
(block_mapping
  (block_mapping_pair
    key: (flow_node) @_uses
    (#eq? @_uses "uses")
    value: (flow_node) @_actions_ghs
    (#match? @_actions_ghs "^actions/github-script"))
  (block_mapping_pair
    key: (flow_node) @_with
    (#eq? @_with "with")
    value: (block_node
      (block_mapping
        (block_mapping_pair
          key: (flow_node) @_run
          (#eq? @_run "script")
          value: [
            (flow_node
              (plain_scalar
                (string_scalar) @injection.content))
            (block_node
              (block_scalar) @injection.content)
          ]
          (#set! injection.language "javascript"))))))

; Comment-driven SQL injection.
; Example:
;   #language=sql
;   query: SELECT * FROM users
(block_mapping
  (comment) @_sql_comment
  [
    (block_mapping_pair
      value: (flow_node
        (plain_scalar
          (string_scalar) @injection.content)))
    (block_mapping_pair
      value: (block_node
        (block_scalar) @injection.content))
  ]
  (#match? @_sql_comment "^#\\s*language\\s*=\\s*[sS][qQ][lL]\\s*$")
  (#set! injection.language "Embedded SQL"))

; Key-name SQL injection.
; Matches keys where `sql` appears as its own token, such as:
; sql, sql_query, query_sql, foo-sql-bar
([
   (block_mapping_pair
     key: (flow_node
       (plain_scalar
         (string_scalar) @_sql_key))
     value: (flow_node
       (plain_scalar
         (string_scalar) @injection.content)))
   (block_mapping_pair
     key: (flow_node
       (plain_scalar
         (string_scalar) @_sql_key))
     value: (block_node
       (block_scalar) @injection.content))
 ]
  (#match? @_sql_key "(^|[-_])[sS][qQ][lL]($|[-_])")
  (#set! injection.language "Embedded SQL"))
